inherit NPC;
#include "star.h"
int greeting(object me);


void create()
{
        set_name("修道士", ({"xiu daoshi", "daoshi"}));
        set("long", "他身穿一件黑色修道士的长袍,长袍遮住了他的全身,连脸都看不到,不知道他的年龄,和性别。
双手也捅在袖子里,鞋子被黑色长袍一遮到底,只有胸口的灰色十字架被风吹起来飘动一下
这个神秘的蒙面人看起来没有一点活着的气息,给人毛骨悚然的危险感。 \n");
        set("gender","男性");
        set("title", "神秘的");
        set("age",41);
        set("attitude", "friendly");
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",100000);
          set("daoxing",2600000);
        set("chat_chance",20);
        set("chat_msg", ({
                "神秘的修道士说道：请象黑暗下跪，我将给你冥王哈帝斯的力量，同意就说《agree》\n"
        }));
          set_skill("dodge", 100);
          set_skill("force", 100);
          set_skill("parry", 100);
          set_skill("unarmed", 100);
          set_skill("sword", 100);
         set_skill("westsword",100);
          set_skill("boxing",100);
         set_skill("baiyang", 100);
        set_skill("yaofa", 100);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","yaofa");
         set("max_force", 1000);
         set("force", 2000);
         set("max_mana",1000);
         set("mana",2000);
         set("mana_factor",50);
         set("force_factor", 50);
       set("max_kee", 1000);
       set("max_gin", 1000);
        set("max_sen", 1000);

        setup();
        carry_object(__DIR__"obj/by_cloth")->wear();
//        carry_object(__DIR__"obj/westsword")->wield();
}
 

void init()
{
        object me = this_player();
        ::init();
        add_action("do_agree", "agree");
          if(living(me))
       
//				remove_call_out("greeting");
                call_out("greeting", 1, me);
}



int greeting(object me)
{
     if( !me || !visible(me) || environment(me) != environment() ) return 0;
     
	if (me->query_temp("12gong/cike")=="done")
    {
		command("say 怎么样,得手了吗?");
	    return 0;
	}
	command("say " + "嘿嘿........看样子你也是来杀雅典娜的吧? 闯过黄金十二宫已经是
困难重重了别说杀女神雅典娜了,不如我教你一个办法,一定能杀雅典娜,你可愿意
按我说的去做?(agree)\n");
	 
}

int do_agree(string arg)
{
	 object bishou;
    object me=this_player(), npc=this_object(), ob;
	string myname=me->query("id");
	if (me->query_temp("12gong/cike")!="done")
	{
    
	command("say 见到了雅典娜就用这把匕首刺她(stab),她没有防备一定会被刺中
的,她身上可有顶级防具哦!\n\n");
	me->set_temp("12gong/cike","done");
    bishou = new("/d/12gong/npc/obj/bishou");
bishou->move(me);
command("grin");

	return 1;
	}
return 0;
}
