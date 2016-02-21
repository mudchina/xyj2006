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
  set_name("西游记库管", ({"semder", "sender", "master"}));
        set("long", "他身上带有各种兵器和金甲(armor)，如果需要你可以问他(yao)。\n");
  set("gender", "男性");
  set("age", 46);
  set("str", 30);
  set("int", 25);
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
  

}



void init()
{
  add_action("do_yao", "yao");
  add_action("do_huan", "huan");
}

int do_yao(string arg)
{
  object me=this_player(), npc=this_object(), obj;
  
  if( !arg ||
     (arg != "blade"
   && arg != "sword"
   && arg != "fork"   
   && arg != "spear"
   && arg != "hammer"
   && arg != "staff"
   && arg != "stick"
   && arg != "whip"
   && arg != "armor"
   && arg != "dun"))
    return notify_fail(CYN"西游记库管道：对不住，你要的东西我这里没有。\n"NOR);
    if(count[arg]>=total)
	return notify_fail(CYN"西游记库管道：对不住，你要的东西我已经发完了。\n"NOR); 
    if (arg == "body"
     || arg == "head"
     || arg == "feet"
     || arg == "waist")
    {
	if (me->query_temp("mark/jjf_armor") >=4)
	    return notify_fail(CYN"西游记库管怒道：你要了这么多件衣甲，还不够？！\n"NOR);
	me->add_temp("mark/jjf_armor", 1);
    }
    else
    {
	if (me->query_temp("mark/jjf_weapon") >= 3)
	    return notify_fail(CYN"西游记库管怒道：你要了这么多件兵器，还不够？！\n"NOR);
	me->add_temp("mark/jjf_weapon", 1);
    }
    count[arg]+=1;
    if (arg== "bow") {
        obj=new("/d/obj/weapon/archery/mugong");
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
	obj->set("jjf_weapon", 1);
        command("say 这位"+RANK_D->query_respect(me)+"，"+obj->query("name")+"为数不多，千万别随便扔。");
	command("say 要是您不再需要，请还(huan)给我。");
        message_vision("西游记库管给$N一"+obj->query("unit")+obj->query("name")+ "。\n", me);
        obj->move(me);
    }
    else if (arg == "body"
     || arg == "head"
     || arg == "feet"
     || arg == "waist") {
        obj=new(__DIR__"obj/"+arg);
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
	obj->set("jjf_armor", 1);
        command("say 这位"+RANK_D->query_respect(me)+"，"+obj->query("name")+"为数不多，千万别随便扔。");
	command("say 要是您不再需要，请还(huan)给我。");
        message_vision("西游记库管给$N一"+obj->query("unit")+obj->query("name")+ "。\n", me);
        obj->move(me);
    }
    else {
	obj=new(__DIR__"obj/"+arg);
        obj->set("no_sell", 1);
        obj->set("no_drop", 1);
        obj->set("no_give", 1);
	obj->set("jjf_weapon", 1);
        command("say 这位"+RANK_D->query_respect(me)+"，"+obj->query("name")+"为数不多，千万别随便扔。");
	command("say 要是您不再需要，请还(huan)给我。");
        message_vision("西游记库管给$N一"+obj->query("unit")+obj->query("name")+ "。\n", me);
        obj->move(me);
    }

    return 1;
}

string try_me()
{
  command("say 巫师们亲自破费，准备了一些兵器和衣甲。");
  return ("只要是大家需要就可以拿一套去用。");
}

int do_huan(string arg)
{
	object me=this_player(), npc=this_object(), ob;

	if(!objectp(ob=present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	if(ob->query("jjf_weapon")==1) {
		message_vision("$N拿出" + ob->short() + "给$n。\n", me, npc);
		command("say 不错，不错，这"+ob->query("unit")+ob->query("name")+"修修还可以用。");
		command("thank "+me->query("id"));
		destruct(ob);
		me->add_temp("mark/jjf_weapon", -1);
	}
	else if(ob->query("jjf_armor")==1) {
		message_vision("$N拿出" + ob->short() + "给$n。\n", me, npc);
		command("say 不错，不错，这"+ob->query("unit")+ob->query("name")+"修修还可以用。");
                command("thank "+me->query("id"));
                destruct(ob);
                me->add_temp("mark/jjf_armor", -1);
	}
	else
		return notify_fail(CYN"西游记库管道：对不住，这好象不是我发的东西吧！\n"NOR);

	return 1;
}

