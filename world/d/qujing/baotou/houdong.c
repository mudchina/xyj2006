// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "后洞");
  set ("long", @LONG

后洞里髯着一堆一堆的篝火，洞的东边砌了一个石灶，上有一
口大铜锅。西边有一内厅，厅里铺有各式兽皮，正中有一大床
铺着绒毛垫。洞壁上有一道裂痕，延伸到洞顶。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"qiandong",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 1,
      ]));

  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb ()
{
  object who = this_player ();
  string midong = __DIR__"midong1";

  message_vision ("$N攀住岩壁，向上爬去。\n",who);  
  if (who->is_busy() || who->is_fighting() || 
	  present ("yao guai",this_object()))
  {
    message_vision ("$N从岩壁上滑了下来！\n",who);  
    return 1;
  }
  midong[strlen(midong)-1] = '1'+random(5);
  who->move(midong);
  who->start_busy(2,2);

	if( random(2) ) {
  call_out ("sleeping",1,who);
  return 1;
	}
  call_out("fainting",1,who);
  return 1;
}

void sleeping (object who)
{
  message_vision ("秘洞里散发着一股刺鼻的腥气，$N顿时昏昏然。\n\n",who);  
  message_vision ("$N勉强眨了眨惺忪的眼睛，打了个哈欠。\n",who);  
  who->set("last_sleep",time()-270);
  who->interrupt_me();
  who->command_function("sleep"); 
}
void fainting (object who)
{
	message_vision("突然从暗口中喷出一股紫烟，$N顿时头重脚轻。。。\n", who);
	who->unconcious();
}
