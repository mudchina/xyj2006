
inherit ROOM;

void create()
{
   set("short", "紫竹林");
   set("long", @LONG

普陀后山的紫竹林。也是观音菩萨闲憩常到的所在。紫竹细疏，
清风微拂。漫步于此，世事之纷扰顿时烟消云散。
LONG
   );
   set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"zhul"+sprintf("%d", random(6)),
  "northeast" : __DIR__"zhuli0",
  "south" : __DIR__"zhul"+sprintf("%d", random(6)),
]));

   setup();
   replace_program(ROOM);
}
