//Rewritten by vikee for XLQY-ZQ station.
//2001-2-16 16:21
//note: I wrote it for WZG players.
// condition : 1 .family/family_name == wzg  2. daoxing > 1500 years
// virtue: the player who was founded can't know someone else is finding him.
//         so it is Wzg's players is benifit from it.

#define RUMORCENTER "/d/city/rumorcenter"
#include <ansi.h>
inherit ITEM;
object room;

void create()
{
	  set_name("水晶球", ({"shuijing qiu","crystal","ball","qiu"}));
	  set_weight(200);
	  set("unit", "只");
	  set("long", "一只鎏光四溢的水晶球。\n");
	  set("no_drop",1);
	  set("no_get",1);
	  set("no_give",1);
	  set("value", 10000);
	  setup();
	  room=load_object(RUMORCENTER);
	  set("room",room);
}

void init() 
{
  add_action("do_detect","detect");
  //this action is added by vikee --zhanbu
  add_action("do_zhanbu", "zhanbu");
}


int do_detect(string arg)
{
  mapping rumor;
  int number;
  object me=this_player();
  object ob=this_object();

  if (! arg || sscanf(arg, "%d", number)!=1) 
		return notify_fail("用法：detect(1-10) \n");

  if (number<1 || number>10) 
		return notify_fail("用法错误！\n");

  if (!room) 
  {
		set("value",0);
		write("这只水晶球已经失去神力了。\n");    
		write("水晶球化成一滩清水流了一地。\n");
		destruct(this_object());
		return 1;
  }

  if (me->query("mana")<100)
		return notify_fail("你的法力不够，无法与水晶球沟通。\n");
  
  rumor=room->reveal(number);
  set("rumor",rumor);
  me->add("mana",-10);
  message_vision(HIG"$N捧着水晶球，口中喃喃自语。\n"NOR,me);
  
  if (!rumor) 
  {
		tell_object(me,"可是什么也没有发生。\n");
		return 1;
  }
  
  tell_object(me,CYN"你请教水晶球：刚才「"+rumor["body"]+"」是谁说的？\n"NOR);
  
  if (!rumor["disclose"])
	    tell_object(me,HIB"水晶球回答你：天机不可泄露。\n"NOR);
  
  else
  {
		tell_object(me,MAG"水晶球缓缓的转动着，你仿佛从中看到了一个身影。\n"); 
		tell_object(me,HIR"人影越来越清晰，你仔细一看，原来是"HIW+rumor["name"]+HIR"("+rumor["id"]+")！\n"NOR);
  }
  return 1;
}  


int do_zhanbu(string arg)
{
        object ob, zhanbu, *ob_list;
        object me = this_player();    
        
       		if (!arg)
			return notify_fail("指令格式：zhanbu <人物>\n");        
		
		if (me->query("mana")<100)
		    	return notify_fail("你的法力不够，无法与水晶球沟通。\n");	  

		if( me->query("family/family_name")!= "五庄观" )
			return notify_fail("你非五庄观弟子，怎么也弄不懂这八卦的法门。\n");

		if( me->query("daoxing") < 1500000)
			return notify_fail("你道行还不够耶...");



       		me->add("mana",-100);
        	message_vision(HIW"$N捏着手指，按照子、丑、寅、卯、辰、巳、午、未、申、酉、戌、亥的方位，仔细的掐算着。。。\n"NOR, me);

		
		ob = find_player(arg); //just only for finding the player
		

		if (!ob || (ob->query("env/invisibility") && wizardp(ob) )) 
	  		return notify_fail(CYN"这个人好象不在线耶...\n"NOR);
	  				
		zhanbu = environment(ob);

        	if (!zhanbu) 
			return notify_fail(CYN"这个人不知道在那里耶...\n"NOR);

		if(wizardp(ob))
			return notify_fail(CYN"水晶球里始终雾气蒙蒙，你什么也看不清！\n"NOR);

		tell_object(me,HIM"水晶球缓缓的转动着，你仿佛从中看到了一个身影。\n"); 
        	printf(HIM"原来%s(%s)在%s活动耶...。\n"NOR,(string)ob->name(),(string)ob->query("id"),(string)zhanbu->query("short"));
        
        	return 1;

}

