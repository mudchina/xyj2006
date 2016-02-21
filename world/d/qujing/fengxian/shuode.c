// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "硕德堂");
  set ("long", @LONG

硕德堂里有六根绿色凤凰柱，四周摆满香草花坛。屋中有一对
太师椅，墙边是一溜兽皮靠背椅。此堂乃是郡主休息品茶的专
厅，现用作以接待祭雨贤哲的场所。
    
LONG);

  set("exits", ([
        "northwest"    : __DIR__"shang",
        "southwest"    : __DIR__"junhou",
      ]));
  setup();
}

