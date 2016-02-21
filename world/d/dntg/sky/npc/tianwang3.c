//modified by vikee
//2000.10
inherit NPC;
#include "huoyannpc2.h"

string send_me(object me);
void create()
{
        set_name("魔礼青", ({ "moli qing", "zengzhang tianwang", "qing", "tianwang" }) );
        set("gender", "男性" );
	set("long",
		"增长天王为四大天王之首, 身高二丈四尺, 善用一杆长枪, \n"
		"枪法登峰造极, 更有密传「青云宝剑」, 「地，水，火，风」\n"
		"四式一出, 大罗金仙也难逃。\n"
	);
	set("age",50);
	set("title", "增长天王");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_kee",1100);
	set("kee",1100);
	set("max_sen",1100);
	set("sen",1100);
	set("combat_exp",2000000);
    set("daoxing",1500000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 80);
	set("mana_factor",80);
	
    
    set("nkgain", 800);

	set_skill("sword",200);
	set_skill("bainiao-jian", 200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("throwing",200);
	set_skill("ningxie-force",200);
	set_skill("force",200);
	set_skill("spells", 200);
	set_skill("moshenbu", 200);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bainiao-jian");
	map_skill("sword","bainiao-jian");
	map_skill("force", "ningxie-force");
	set("inquiry", ([
		"name" : "在下增长天王魔礼青，奉圣谕把守南天门。",
		"here" : "这里就是南天门, 入内就是天界了。",
		"回去": (: send_me :),
		"back": (: send_me:),
	]) );

	setup();
carry_object("/d/sky/obj/zhanyaojian")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

string send_me(object me)
{
        me=this_player();
	        if( me->is_fighting() )
		return ("刚来就惹麻烦，鬼才要理你！\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
		return ("忙完再说吧。。。\n");

	message_vision("增长天王哈哈大笑，对$N说道：本王这就送你回去！\n", me);
	message_vision("增长天王飞起一脚把$N踢了下去。。。\n", me);
        me->move("/d/changan/nbridge");
	tell_room( environment(me), "「咕咚」一声，从天上掉下个人来！\n", ({me}));
	write("你从天上摔了下来，搞了个鼻青脸肿！\n");
	return ("老夫脚正痒痒。。。\n");
}

void hurting(object me, object ob)
{
   remove_call_out("hurting");

   if(environment(me)!=environment(ob) || !me->is_fighting()) return;
   me->command_function("perform chaofeng");

   call_out("hurting",5+random(6),me,ob);
}

