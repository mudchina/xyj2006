// Room: /u/mes/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

厨房里支起了数口大锅，灶下烈火熊熊，整日不息。蒸笼里传出的香
气却甚是古怪，看来这包子里大有文章。墙上有张告示(gaoshi)，油
渍斑斑，字迹颇为模糊。
LONG);

  set("valid_startroom", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "近来缺乏新鲜人肉，各洞小仙若有擒获，请速送厨房。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dong2",
]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yanshu": 1,
]) );
  setup();
    call_other("/obj/board/wudidong_b", "???");
}
void init()
{
    add_action("do_save", "save");
}
int do_save(string arg)
{
    object me=this_player();
    if (arg) return 0;
    if (me->query("family/family_name")!="陷空山无底洞")
    {
        me->save();
        tell_object(me, "档案储存完毕。\n");
        return 1;
    }
    return 0;
}
