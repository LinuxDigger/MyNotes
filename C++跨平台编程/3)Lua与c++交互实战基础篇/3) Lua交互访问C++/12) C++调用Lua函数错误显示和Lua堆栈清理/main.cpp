extern "C"
{
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}


int main()
{
	lua_State *lua = lua_open();
	// �򿪻�����
	luaopen_base(lua);
	luaopen_string(lua);
	luaopen_table(lua);

	
	// ����ű�
	if (luaL_loadfile(lua, "main.lua"))
	{
		const char *error = lua_tostring(lua, -1);
		printf("lua load error:%s\n", error);
		return -1;
	}

	// ִ�нű�
	if (lua_pcall(lua, 0, 0, 0))
	{
		const char *error = lua_tostring(lua, -1);
		printf("lua call error:%s\n", error);
		return -1;
	}

	printf("top is %d\n", lua_gettop(lua));
	lua_getglobal(lua, "event2");
	if (lua_pcall(lua, 0, 0, 0) != 0)
	{
		printf("call event failed %s\n", lua_tostring(lua, -1));
		lua_pop(lua, 1);
	}
	printf("top is %d\n", lua_gettop(lua));

	lua_close(lua);
	getchar();
	return 0;
}