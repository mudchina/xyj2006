//qinping.c
//created 5-10-97 pickle

/************************************************************/

#include <ansi.h>
inherit F_MASTER;
inherit NPC;
string try_me();
int total=random(20);
mapping count=([]);
/************************************************************/

void create()
{
  set_name("秦平", ({"qin ping", "qin", "master"}));
  set("title", "将军府管家");
  set("gender", "男性");
  set("age", 46);
  set("str", 30);
  set("int", 25);
  set_skill("spear", 70);
  set_skill("force", 70);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("yanxing-steps", 70);
  set_skill("bawang-qiang", 70);
  set_skill("lengquan-force", 70);
  set_skill("unarmed", 70);
  set_skill("changquan", 70);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 200);
  set("max_kee", 600);
  set("force", 500);
  set("max_force", 400);
  set("force_factor", 20);
  set("combat_exp", 80000);

  setup();
  set("inquiry", ([
		   "兵器": (: try_me :),
		   "衣甲": (: try_me :)
]) );
  
  create_family("将军府", 3, "蓝");
  carry_object("/d/obj/armor/tenjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}
/************************************************************/
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  command("pat "+me->query("id"));
  command("say 很好，时下正是用人之际，"+myname+"多加努力，他日必定有成。");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}

/************************************************************/
void init()
{
  add_action("do_yao", "yao");
}

int do_yao(string arg)
{
  object me=this_player(), npc=this_object(), obj;
  
  if((string)me->query("family/family_name")!="将军府")
    return notify_fail(CYN"秦平道：对不住，将军府衣甲兵器只发给本派子弟。\n"NOR);
  if( !arg ||
     (arg != "blade"
   && arg != "sword"
   && arg != "axe"
   && arg != "fork"
   && arg != "dagger"
   && arg != "hammer"
   && arg != "mace"
   && arg != "spear"
   && arg != "staff"
   && arg != "stick"
   && arg != "throwing"
   && arg != "whip"
   && arg != "bow"
   && arg != "body"
   && arg != "head"
   && arg != "feet"
   && arg != "waist"))
    return notify_fail(CYN"秦平道：对不住，你要的东西我这里没有。\n"NOR);
    if(count[arg]>=total)
	return notify_fail(CYN"秦平道：对不住，你要的东西我已经发完了。\n"NOR); 
    if (arg == "body"
     || arg == "head"
     || arg == "feet"
     || arg == "waist")
    {
	if (me->query_temp("mark/jjf_armor") >=4)
	    return notify_fail(CYN"秦平怒道：你要了这么多件衣甲，还不够？！\n"NOR);
	me->add_temp("mark/jjf_armor", 1);
    }
    else
    {
	if (me->query_temp("mark/jjf_weapon") >= 3)
	    return notify_fail(CYN"秦平怒道：你要了这么多件兵器，还不够？！\n"NOR);
	me->add_temp("mark/jjf_weapon", 1);
    }
    count[arg]+=1;
    if (arg== "bow") {
        obj=new("/d/obj/weapon/archery/mugong");
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
        command("say 这位"+RANK_D->query_respect(me)+"，"+obj->query("name")+"为数不多，千万别随便扔。");
        message_vision("秦平给$N一"+obj->query("unit")+obj->query("name")+ "。\n", me);
        obj->move(me);
    }
    else {
        obj=new(__DIR__"obj/"+arg);
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
        command("say 这位"+RANK_D->query_respect(me)+"，"+obj->query("name")+"为数不多，千万别随便扔。");
        message_vision("秦平给$N一"+obj->query("unit")+obj->query("name")+ "。\n", me);
        obj->move(me);
    }
    return 1;
}

string try_me()
{
  command("say 秦将军亲自破费，准备了一些兵器和衣甲。");
  return ("只要是将军府的弟子就可以拿一套去用。");
}
/************************************************************/
