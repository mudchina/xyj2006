// created by snowcat 4/4/1997
// room: /d/nuerguo/shanpo.c

inherit ROOM;

void create ()
{
  string dir;
  set ("short", "山路");
  set ("long", @LONG

野润烟光淡，沙暄日色曛。一路行来景色秀丽。再往西行就
到子母河了。过了河就是西梁女国地界。

LONG);

/*
  dir = __DIR__;
  dir[strlen(dir)-8] = 0;
*/
  dir = "/d/";
  set("exits", ([
         "southeast" : dir+"qujing/jindou/shanlu6",
         "west" : __DIR__"eastriver1",
      ]));
  set("outdoors", __DIR__"");

  //set("objects",([
  //      __DIR__"obj/story" : 1,
  //     ]));

  setup();
}






