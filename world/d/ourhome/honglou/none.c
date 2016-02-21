// Room: /u/hkgroup/nonsense
inherit ROOM;

void create ()
{
  set ("short", "画楼");
  set ("long", @LONG

　　　　滴不尽相思血泪抛红豆，
　　　　开不完春柳春花满画楼(painting)

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "painting" : "
         画中
             一轮太阳
                 悬在半空
                     终于
                         将落未落
                         将起未起

         窗外
             一抹夕照
                 归途半路
                     终于
                         无影无踪
                         无声无息

         桌前
             一束酒花
                 微醉半开
                     终于
                         唏也不是
                         嘘也不是

         手中
             一支画笔
                 徘徊半晌
                     终于
                         促膝而卧
                         抱臂而憩

",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"cave",
]));
  set("no_fight", 1);

//  set("objects", ([
//           __DIR__"npc/niu.c": 1,
//]));

  setup();
}
