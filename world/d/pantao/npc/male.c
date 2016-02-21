// by snowcat 5/29/1997

#include <ansi.h>

inherit NPC;
int longwang();

void create()
{
  string *names = ({ "仙官", "仙将", "仙卿", });
  string name = names[random(sizeof(names))];

  set_name(name,({ "xian" }) );
  set("gender", "男性" );
  set("long", "一位紫绶金章芙蓉冠的"+name+"。\n");
  set("age", 100+random(100));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",400000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 100);
  set("max_gin", 4000);
  set("max_kee", 4000);
  set("max_sen", 4000);
  set("max_mana", 4000);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_skill("spear",100);
  set_skill("force",100);
  set("chat_chance",5);
  set("chat_msg",({(: random_move :)}));
          set("inquiry", ([
	    "泾河龙王" : (: longwang :),	    
	 ]) );
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}

int longwang()
{
	 object me,ob;
    me=this_player();
    ob=this_object();

	  if (!me->query_temp("longwang_yuan"))
	  return 0;
	  if (ob->query("name")!="仙将")
	  return 0;
	command("nod" + me->query("id"));
	message_vision("\n仙将拱手答道："+RANK_D->query_respect(me)+"若问别的小仙只怕知道不多，但问起那泾河龙王被斩之事，
	      在下还是略知一二．\n",me);
	message_vision("\n　　前日，小仙奉玉帝旨意命泾河龙王隔日辰时布云，巳时发雷，午时下雨，未
时雨足，共降雨水三尺三寸零四十八点．谁知那泾河龙王竟违旨不尊，到次日，
巳时布云，午时发雷，未时下雨，申时雨止，却只得三尺零四十点，改了一个时
辰，克了三寸八点．玉帝大怒，命大唐丞相魏征，梦斩泾河龙王，此事传到东海
老龙王那里，只惊的熬广大病三日，不知现在可有好转？\n",me);
	me->delete_temp("longwang_yuan");
	me->set_temp("longwang_xian",1);
	call_out("longwang1",2);
	return 1;
}

void longwang1()
{
	 object me,ob;
    me=this_player();
    ob=this_object();
	message_vision(WHT"\n$N还礼道：大仙放心，我刚从东海龙宫来，那东海龙王精力健旺，应该没什么
          大碍了．\n"NOR,me);
	message_vision("\n仙将点头道：那就好，龙王执掌下界雨水，可不能有何闪失，否则天下百姓何以为
          食啊，这可是半点都不能马虎的．\n",me);
	message_vision(WHT"\n$N说道：那在下就不多打扰了，告辞．\n"NOR,me);
}