// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "斋栈");
  set ("long", @LONG

斋栈原为凤仙郡迎客栈，因久旱无雨，栈主便将此栈改为斋栈
以示皈依之诚心。斋栈里为客免费提供饮用水，里屋为斋室，
为路客提供垫饥的小食。
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao7",
        "north"    : __DIR__"zhaishi",
      ]));
  set("resource", ([
        "water"    : 1,
      ]));
  set("objects", ([
        __DIR__"npc/sg1" : 1,
      ]));
  set("valid_startroom",1);
  setup();
}

