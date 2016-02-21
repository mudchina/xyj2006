// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(""HIY"一叶知秋"NOR"", ({"zong guan", "vikee"}));
	set("long", "他是发送装备的总管一叶知秋,你可以(list)查看想要的东西。\n");
	set("gender", "男性");
	set("age", 20);
	set("per", 40);
	set("title",""HIG"西游记2006装备总管");
	set_skill("literate", 141);
	set("chat_chance",20);
    set("chat_msg", ({
        "一叶知秋轻声告诉你：你可以用list指令列出想要的东西！\n",
        "一叶知秋轻声告诉你：你可以用yao指令向总管我索取装备。\n",
        "一叶知秋很神气的说：我就是总管，总管就是我！\n",		
        }));
	setup();
	carry_object("/d/obj/cloth/magua")->wear();
}

void init()
{
	::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_ji","ji");
  add_action("do_throw","throw");
  add_action("do_list","list");
  add_action("do_yao","yao");
}

void die()
{
 return;
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
	message_vision("$N看样子想打架，但一叶知秋很有涵养,不和$N动粗。\n",who,me);
     return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
message_vision("$N看样子想杀死一叶知秋，但一叶知秋是文化人,没跟$N一般见识。\n",who,me);

    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N对着一叶知秋结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who,me);

  return 1;
}


int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想偷东西，但总是有贼心没贼胆。\n",who,me);

  return 1;
}


int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想对一叶知秋祭法宝，前思后想，还是没敢。\n",who,me);

  return 1;
}

int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N掏出暗器，看了看一叶知秋，信心不足，又把暗器收了起来。\n",who,me);

  return 1;
}

int do_list(string arg)
{
	object who = this_player();
	object me = this_object();
  message("vision",""HIG"\n─────────────────────────────────────
          \n"HIY"盔甲："HIC"
          1.金甲(armor)     2. 披风(pifeng)   3.盾牌(shield)
          4.铁盔(kui)       5. 战袍(cloth)    6.踏云靴(shoes)
          \n"HIY"兵器："HIC" 
          1.降魔棒(stick)   2. 青虹剑(sword)  3.软龙筋(whip)
          4.金刀(blade)     5. 短铁爪(zhua)   6.黄铜禅杖(staff)
          7.宣花斧(axe)     8. 月牙铲(fork)   9.梅花锤(hammer)
"HIG"\n─────────────────────────────────────\n"NOR"",who,me);

  return 1;
}

int do_yao(string arg)
{
	string type;
	object ob;
	object who=this_player();
	object me=this_object();
	if (who->query("combat_exp")>500000)
		return notify_fail("凭您的功夫，还是自己去打装备吧! :P\n");
    if (!arg)
		return notify_fail("你想要什么？兵器？还是盔甲？(比如:yao sword)\n");
	else 
	{
		sscanf(arg,"%s",type);
			switch(type)
			{
			//盔甲
			case "armor":
				ob=new("/u/vikee/give/armor.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "pifeng":
				ob=new("/u/vikee/give/pifeng.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shield":
				ob=new("/u/vikee/give/shield.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "shoes":
				ob=new("/u/vikee/give/shoes.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "cloth":
				ob=new("/u/vikee/give/cloth.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "kui":
				ob=new("/u/vikee/give/kui.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
				//兵器
			case "sword":
				ob=new("/u/vikee/give/sword.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "whip":
				ob=new("/u/vikee/give/whip.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "blade":
				ob=new("/u/vikee/give/blade.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "stick":
				ob=new("/u/vikee/give/stick.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "stick":
				ob=new("/u/vikee/give/stick.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "fork":
				ob=new("/u/vikee/give/fork.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "hammer":
				ob=new("/u/vikee/give/hammer.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "axe":
				ob=new("/u/vikee/give/axe.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "staff":
				ob=new("/u/vikee/give/staff.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;
			case "zhua":
				ob=new("/u/vikee/give/zhua.c");
				ob->move(who);
				tell_object(who,"一叶知秋把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
				break;           

			}
	}
return 1;

}
