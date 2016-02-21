//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("妖怪", ({"yao guai","yao","guai"}));
          set("long","他本是卷帘大将，因蟠桃会失手打破玻璃盏，被贬到下界。\n");
          set("gender", "男性");
          set("age", 23);
          set("per",30);        
          set("combat_exp", 1500000);
	  set("daoxing",1500000);
          set("per", 30);
          set("str", 30);
          set("max_kee", 1200);
          set("kee",1200);
          set("force_factor",20);
          set("max_sen", 800);
          set("env/wimpy",70);
          set("sen",800);
          set("force", 4000);
          set("max_force", 2000);
          set("max_mana", 1000);
          set("mana", 2000);
          set_skill("unarmed", 140);
          set_skill("dodge", 140);
          set_skill("force", 140);
          set_skill("parry", 140);
          set_skill("staff", 140);
          set_skill("spells", 140);
          set_skill("buddhism",140);
          set_skill("jienan-zhi", 140);
          set_skill("lotusforce", 140);
          set_skill("lotusmove", 140);
          set_skill("lunhui-zhang", 140);
          map_skill("spells", "buddhism");
          map_skill("unarmed", "jienan-zhi");
          map_skill("force", "lotusforce");
          map_skill("staff", "lunhui-zhang");
          map_skill("parry", "lunhui-zhang");
          map_skill("dodge", "lotusmove");

         setup();
        carry_object("/d/qujing/liusha/obj/staff")->wield();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  set_leader(ob);
  ::kill_ob(ob);
  call_out ("checking",3,this_object());
  call_out ("back",5,this_object());

}
void checking(object me)
{
  object ob=query_temp("my_killer");
  object where = environment(me);
  object room = load_object("/d/qujing/liusha/riverside");
  if( present(ob,where) )
  {
  message_vision (HIY"\n你忽然感觉到一阵胸闷，急抽身向外走！\n",me);
  message_vision ("你和$N同时从水面上跳了出来！\n"NOR,me);
  me->move(room);
  ob->move(room);
  }
  return;
}

void back(object me)
{
        object ob = query_temp("my_killer");
        object where = environment(me);
        object room = load_object("/d/qujing/liusha/cave");
        if( me->is_fighting() )
        call_out("back",1,me);
        if( ! where || where->query("short") != "洞内" )
                {
        message_vision(HIR"$N大喝一声：有本事，咱们水底下见。\n",me);
        message_vision("只见$N虚晃一招，跳入水中。\n"NOR,me);
        me->move(room);
        call_out("checking",2,me);
                }
        return;        
}
void destruct_me (object me)
{
  destruct (me);
}

void die()
{
  object here;        
  object ob = query_temp("my_killer");
  object me = this_player();
  object yudi=new(__DIR__"yudi");

	if (ob)
  	{
	ob->set_temp("sha_killed","yes");  
	message_vision ("\n忽然天上传来玉帝的声音。\n",me);
  	message_vision ("\n你发现$N早已消失的无影无踪．\n",me);
	here=environment(ob);
	yudi->move(here);
  	}
  destruct(this_object());
 return;
}
void unconcious ()
{
  die ();
}
