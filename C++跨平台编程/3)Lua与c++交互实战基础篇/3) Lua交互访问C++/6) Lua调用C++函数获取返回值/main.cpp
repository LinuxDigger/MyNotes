extern "C"
{
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}

int CTestRe(lua_State *L)
{
	//lua_pushstring(L, "return value");
	lua_newtable(L);
	// ����key value
	lua_pushstring(L, "name");
	lua_pushstring(L, "Dejan");
	lua_settable(L, -3);
	lua_pushstring(L, "age");
	lua_pushnumber(L, 20);
	lua_settable(L, -3);

	return 1;
}

int main()
{
	lua_State *lua = lua_open();
	// �򿪻�����
	luaopen_base(lua);
	luaopen_string(lua);
	luaopen_table(lua);
	lua_register(lua, "CTestRe", CTestRe);

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

	getchar();
	return 0;
}