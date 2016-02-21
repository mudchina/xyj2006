// mon. 4/30/97

inherit ROOM;

string look_zi();

void create ()
{
  set ("short", "二郎庙");
  set ("long", @LONG

这里是二郎真君的庙宇。想当年齐天大圣孙悟空曾与二郎神
在此一场恶斗，如今故人依在，只是冷落了许多。真君正端
坐案前，见你进来，似乎早已知道来意，似笑非笑地上下打
量着你。右首一根大红柱子，好象刻了些字(zi)。
LONG);

  set("exits", ([ /* sizeof() == n */
  "out" :__DIR__"guanjiang",
]));

  set("item_desc", ([
    "zi": (: look_zi :),
  ]));

  set("objects",([
  __DIR__"npc/erlang" : 1,
 ]));

  setup();
}

string look_zi()
{ string str;
  object me=this_player();

  if(me->query("kill")) {
    str="\n\n        如何杀死其他玩家以增长道行\n"; 
    str+="\n\n1．杀死(who -k)所显示的玩家，可以获得对方的部分道行。\n";
    str+="2．对方道行比你高出越多，得到的道行越多。\n";
    str+="3．如果对方道行比你低很多，则很难得到道行。\n";
    str+="4．杀死其他玩家(非who -k所示)，不能得到道行。切记！！！\n";
    str+="5．杀死其他玩家帮你打晕的玩家，不能得到道行。\n";
    str+="6．连续打死同一玩家，得到的道行将越来越少。\n";
    str+="\nＨａｖｅ　ｆｕｎ！Ｂｅ　ｓａｆｅ！\n\n";
  } else {
    str=("你偷眼瞧了瞧柱子上的字，却好象什么也没看见。\n");
  }
  return str;
}


