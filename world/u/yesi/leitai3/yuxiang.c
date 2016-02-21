// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "御相府");
  set ("long", @LONG

御相府里古色古香，下面是花石镶铜地板，上面是银丝琉璃吊灯，廊
厅两边一式紫香木太师椅。据说，相家因阴间救了唐太宗一难，太宗
亲自御批相府专营兵器盔甲，长安的尉迟恭是相府的常客。

LONG);

  set("exits", ([
        "east" : __DIR__"shun2",
        "west" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  2,
      ]));

  setup();
}


