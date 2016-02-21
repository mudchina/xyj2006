inherit ROOM;

void create ()
{
  set ("short", "石屋内");
  set ("long", @LONG

石屋内黑咚咚的，还散发着一股说不上来的怪味，让人闻之欲呕。
周围依稀看到几根铁柱，还残留着几丝血迹。
LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beast" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
//  "east" : __DIR__"yujie2.c",
]));
//      
        set("water", 1);
//  
  setup();
}
