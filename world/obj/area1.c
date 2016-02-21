inherit ITEM;
inherit F_SAVE;

string id;
void create(string name)
{
id=name;
if(!restore_object("/data/city/"+name+".o"))
{
set_name("无效城市", ({ "city" }));
set("no_use",1);
}else {
set_name("城市"+name, ({ "city" }));
set("no_use",0);
	
	}
	setup();
}
string query_save_file()
{
return sprintf(DATA_DIR "city/%s",id);
}
