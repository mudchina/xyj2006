// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "市口");
  set ("long", @LONG

凤仙郡的闹市区，此地各色人等来来往往，更有一些人围在街
心伸头踮脚读着一帖榜文：

  “大天竺国凤仙郡郡侯上官，为榜聘明师，招求大法事。
    慈因郡土宽弘，军民殷实，连年亢旱，累岁干荒。富
    室聊以全生，穷民难以活命。为此出给榜文，仰望十
    方贤哲，祷雨救民，恩当重报。须至榜首。”
        
LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao1",
        "west"    : __DIR__"jiedao4",
        "east"    : __DIR__"jiedao5",
        "up"    : __DIR__"jitai",
        "south"    : __DIR__"jiedao11",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

