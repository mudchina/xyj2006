// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "施恩堂");
  set ("long", @LONG

施恩堂里有三对红漆麒麟柱，屋顶上吊下莲花灯，北面和西面
有数窗，外有亭有石。这里原是上官郡主读书的地方，现在专
门用以接待祈雨法师。
    
LONG);

  set("exits", ([
        "northeast"    : __DIR__"shang",
        "southeast"    : __DIR__"junhou",
      ]));
  setup();
}

