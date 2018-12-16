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

	// ����һ��luaȫ�ֱ���
	lua_pushstring(lua, "Hello");
	lua_setglobal(lua, "test");

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

	

	lua_close(lua);
	getchar();
	return 0;
}