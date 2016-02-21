// skin.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("人皮",({"ren pi", "skin", "pi", "renpi"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","
张翁高邻如晤：

\t你我近邻多年，虽不曾相见，也有若干乡亲之情。今有一事相求，万望张翁
多多费心，日后必当有报。昨闻高邻于田中得铁骷髅一件，此物大有干系，还望老丈
密密藏之。本仙洞近发现一细作，惟有此物可引其现形。若老丈能将此铁骷髅予一有
心之人，令其相助寻出内奸，更是最好。事成之日，下仙自有宝物相赠，吾不食言。
此事机密，勿与他人知晓，莫谓言之不预也。

\t \t \t \t \t \t 地涌夫人顿首。
		   \n");
		set("material", "paper");
		set("unit","张");
		set("value", 0);
	}
}

void init()
{
    if(userp(this_player()))
        add_action("do_tear", "tear");
}
 
int do_tear(string arg){
        object ob,me;
        me=this_player();
        if( !this_object()->id(arg) ) return notify_fail("你要撕什么？\n");
        ob=new(__DIR__"letter");
        ob->move(me);
        message_vision("$N撕开人皮，从中拿出了一个纸卷，展了开来。\n", me);
        destruct(this_object());
        return 1;               
}
