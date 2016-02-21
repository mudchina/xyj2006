// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "膳堂");
  set ("long", @LONG

膳堂是两层饭店，装璜布置十分讲究，楼上楼下各有仙桌仙椅
无数，门口有一凤仙雕花屏风。但堂内无一食客，传言此家不
顾官府禁令，借灾抬价发财已被查封。
    
LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao9",
      ]));
  setup();
}

