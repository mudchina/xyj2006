//Cracked by Roath
inherit NPC;
string ask_book();
void create()
{
        set_name("老者", ({"old man","lao zhe","man"}));
        set("gender", "男性");
        set("age", 58);
        set("long","一个年迂古稀的老人，听说他就爱替别人写状纸，而打报不平。");
        set("attitude", "friendly");
        set("per", 30);
        set("str", 30);
        set("combat_exp",2000);
	set("daoxing",2000);	
        set("max_kee",300);
        set("max_sen",300);
        set("inquiry", ([
                "告状" : (: ask_book :),
                "状纸" : (: ask_book :),
                        ]) );
        setup();
}
string ask_book()
{
        object ob;
        object me = this_player();
        ob = new("/d/jz/obj/paper");
        if(me->query("bellicosity")>100) {
        ob->move(this_player());
        return "看来您好象有血海深仇，这有写好的状纸，告状去吧。";
                                          }
        else
        return "平白无故，告什么状啊！";
}
