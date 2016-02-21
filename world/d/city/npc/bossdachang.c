//Cracked by Roath


inherit NPC;
#include <ansi.h>

void greeting(object me);

void create()
{
        set_name("朱老板", ({"boss dachang", "boss", "dachang"}));
        set("long",@LONG
朱老板原名猪大肠，当年是长安城两大流氓“左捣乱，右猪肠”
之一。有次被捣乱痛扁后卧床不起，百无聊赖之际读史解闷。读
到刘邦周处等人的故事时，悚然有悟。从此奋发读书，潜心习武，
文不成武不就后，毅然下海从商，终于成就了今天的局面。发迹
改名朱大常，身穿绸袍，俨然衣冠中人。
LONG);
        set("title", "长安巨贾");
        set("gender", "男性");
        set("age", 44);
        set("per",18);
        set("kee", 800); 
        set("max_kee", 800);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 3);
        set("chat_msg", ({
         "朱老板对着你喝道：本大爷看你实在很不顺眼，去死吧。\n",
         "朱老板用一种异样的眼神扫视着在场的每一个人。\n",
         "朱老板说道：母鸡，给我一只蛋。\n",
        }));

        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}

void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
void greeting(object who) {
  tell_object(who,"朱老板正盯着你看，不知道打些什么主意。\n");
}
