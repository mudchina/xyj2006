//Cracked by Roath

inherit ROOM;

void start(object leitai) {leitai->start();}

void create ()
{
  set ("short", "观礼台");
  set ("long", @LONG

观礼台由平坦宽适的红木一级级搭成，地下铺着花纹虎皮和金钱豹
皮。台上放着一排排猩红绒面太师椅，可以让贵宾们比较舒适地观
看比赛。参赛选手也可以在这里查询(checkscore)自己的战绩，看
一看高手的排名(list)。

LONG);

  set("exits", ([
        "south"   : "/d/city/wuguan",
//     "up"  :  __DIR__"leitai",
      ]));
  set("no_fight",1);
  set("objects",([__DIR__"scorekeeper":1,]));
  set("no_magic",1);
  setup();
}

void init() { 
  add_action("do_defend","defend");
  add_action("do_checkscore","checkscore");
  add_action("do_list","list");
  add_action("do_ji","ji");
}

int do_ji()
{
  return 1;
}

/*
int do_list() {
  int size;

  object room=find_object(__DIR__"leitai");
  if (!room) room=load_object(__DIR__"leitai");
  size=room->query("size");
  if (size>10) size=10;
  if (!size) return 1;
  write("名次    ＩＤ        积分\n");
  for (int i=1;i<=size;i++) {
  write(sprintf("%2d      %-8s    %d\n",i,room->query("list/"+i),room->query("scores/"+room->query("list/"+i))));
  }
  write("\n");
  return 1;
}
int do_checkscore() {
  object room=find_object(__DIR__"leitai");
  if (!room) room=load_object(__DIR__"leitai");
  room->report(this_player());
  return 1;
}
*/

int do_list() {
  write("有关个人隐私，还是不要多问的好。\n");
  return 1;
}
int do_checkscore() {
  write("你自己的成绩怎么样，自己还不清楚？\n");
 return 1;
}
int do_defend(string arg) {
  object defender=this_player(); 
  object challenger;
  object leitai=find_object(__DIR__"leitai");

  if (!arg) return notify_fail("你要找谁应战？\n");
  if (!challenger=present(arg,this_object()))
      return notify_fail("这里没有这个人。\n");
  if (challenger->query_temp("leitai/challenge")!=defender)
     return notify_fail("这人没有向你挑战。\n");

  if (!leitai) leitai=load_object(__DIR__"leitai");
  if (leitai->query("busy")) 
    return notify_fail("有人正在擂台上交手，请稍候。\n");  

  message_vision("$N接受$n的挑战！\n",defender,challenger);
  if (defender->move(leitai) && challenger->move(leitai)) {
    defender->delete_temp("leitai/being_challenged");
    challenger->delete_temp("leitai/challenge");
    leitai->set("player1",defender);
    leitai->set("player2",challenger);
    leitai->set("busy",1);
    call_out("start",5,leitai);
   }
  return 1;
}
int valid_leave(object who,string dir) {
  if (!wizardp(who) && dir=="up") return 0;
  return 1;
}
