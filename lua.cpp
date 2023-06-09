#include <cstdlib>
#include <lua.hpp>
#include <iostream>

int main(int argc, const char** argv)
{
    int error;
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    const auto&& lua_exit_func_ptr = [](lua_State* L)
    {
        const lua_Integer error = luaL_checkinteger(L, 1);
        exit(int(error));
        return 0;
    };
    lua_pushcfunction(L, lua_exit_func_ptr);
    lua_setglobal(L, "exit");

    if (argc > 1)
    {
        error = luaL_loadfile(L, argv[1]) || lua_pcall(L, 0, 0, 0);
        if (error)
        {
            fprintf(stderr, "%s\n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }
    else
    {
        char buffer[4096];
        while (std::cout << "> ", fgets(buffer, sizeof(buffer), stdin) != nullptr)
        {
            error = luaL_loadstring(L, buffer) || lua_pcall(L, 0, 0, 0);
            if (error)
            {
                fprintf(stderr, "%s\n", lua_tostring(L, -1));
                lua_pop(L, 1);
            }
        }
    }

    lua_close(L);

    return 0;
}
