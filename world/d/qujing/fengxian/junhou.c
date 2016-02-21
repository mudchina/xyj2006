// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "郡侯衙");
  set ("long", @LONG

郡侯衙气氛庄严，四周是紫红凤仙屏风，中间有一檀香高座，
摆了一把玉锦镂花椅。这里原是郡主的内堂，因来客与日俱增，
便将前堂移至此，改为郡侯衙。
    
LONG);

  set("exits", ([
        "northeast"    : __DIR__"shuode",
        "northwest"    : __DIR__"shien",
      ]));
  set("objects", ([
        __DIR__"npc/sg"    : 1,
      ]));
  setup();
}

