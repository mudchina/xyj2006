//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "卧室");
  set ("long", @LONG

卧室相当简陋，地上铺着一张草席，想是荒山野岭这家人就在这上
面睡觉，你不禁叹道：妖魔重生，百姓遭殃啊。

LONG);

  set("exits", ([
        "south"  : __DIR__"indoor",

      ]));
	  set("sleep_room", 1);
	  set("light_up", 1);

  setup();
}

void init()
{
  	add_action("do_sleep", "sleep");
}
int do_sleep(string arg)
{	object ob;
  	object me=this_player();
	if( me->query("obstacle/yz") !="done" || !(me->query_condition("eyeill")))
	{ 
		if(me->query_temp("need_sleep")=="yes")
			me->delete_temp("need_sleep");
	return 0;
	}
	message_vision("$N躺下准备休息一下。\n",me);
	ob=new("/d/qujing/huangfeng/npc/lingji1");
	ob->move(this_object());
	message_vision("$N走了过来，坐到草席前。\n",ob);
	call_out("zhibing",1,me,ob);	
	return 1;
} 
int zhibing(object me,object ob)
{
	message_vision("$N说道：我这敝处，却无眼药的。老汉也有些迎风冷泪，"+
		"曾遇异人，传了一方，\n　名唤‘三花九子膏’，能治一切风眼。你可愿意(agree)一试？\n",ob);
	me->set_temp("lingjiask","yes");
	return 1;
}
	
