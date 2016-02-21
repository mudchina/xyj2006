inherit ROOM;

void create ()
{
  set ("short", "枯松涧");
  set ("long", @LONG

松林边上有一片小的石崖，北面有一条山涧，似乎传来阵阵流水
的声音。涧上有一座小的石桥，远望桥后是一座高的怪石崖，崖
下人影攒动。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"songlin4",
  "north" : __DIR__"guaishiya",
]));
  set("outdoors",1);


  setup();
}

