//Cracked by Roath
//renshenguo-yuan.c

inherit ROOM;

void create ()
{
	set ("short", "人参果园");
	set ("long", @LONG

好大的一遍人参果园！巨大的果树上吊着一枚枚令人垂涎欲滴的
人参果。只是不知道怎样才能弄将下来。据说这人参果娇贵无比，
要是乱摘一气什么都吃不上。
LONG);

	set("exits", 
	([ //sizeof() == 4
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));

	set("outdoors", "wuzhuang");
	set("alternative_die",1);

	setup();
}

void init()
{
	object me, zhenyuan;

	me = this_player();

	if( me->query_temp("used_huangtong_key") == 1 )
	{
		me->delete_temp("used_huangtong_key");
		
		message_vision("只听几声哈哈大笑，镇元大仙走了出来。\n", me);
		message_vision("镇元大仙说道：居然被你发现了。那我们就开个人参果大会吧！\n\n\n", me);

   add_action("do_clear","clear");
		if( !objectp(zhenyuan=present("zhenyuan daxian", environment(me))) )
		{//if zhenyuan already here, we do not need creat another one.
			zhenyuan = new(__DIR__"npc/zhenyuan");
			zhenyuan->move(environment(me));
		}
		zhenyuan->start_renshen();
	}
}

int do_clear() {
  object me=this_player();
  object *env=all_inventory(this_object());
  object zhenyuan=present("zhenyuan daxian",this_object());

  if (!zhenyuan) return notify_fail("镇元大仙不在。\n");
  if (!env) return 0;
  message_vision("$N冲着$n小声嘀咕：“这么多人，人参果园变菜市场了。。。”\n",me,zhenyuan);
  message_vision("$N皱了皱眉，突然朗声道：“我五庄观乃道家修身练道之清净所在，闲杂人等一律请回。”\n",zhenyuan);

  for (int i=0;i<sizeof(env);i++)
   if (env[i]!=me && userp(env[i]) && env[i]->query("daoxing")<10000) zhenyuan->send_back(zhenyuan,env[i]);
  return 1;
}

void alternative_die(object me)
{
       object who=this_object();
      	string here = (string)environment(me);
	string there = who->query_temp("wzg/from");

       message_vision("镇元大仙对着$N叹了一口气,摇了摇头！\n",me);
            there = "/d/city/kezhan";
       me->set_temp("accept",0);
       message_vision("镇元大仙的大袖朝着$N轻轻一罩…\n",me);
       me->move(there);
    
      if ((int)me->query("kee") < 1) me->set("kee",0);
      if ((int)me->query("sen") < 1) me->set("sen",0);
      if ((int)me->query("eff_sen") < 1) me->set("eff_sen",200);
      if ((int)me->query("eff_kee") < 1) me->set("eff_kee",200);
	message_vision("…云中伸出一只巨大的衣袖轻轻一抖，只见$N从里面滑了出来。\n",me);
	return ;
}