inherit BULLETIN_BOARD;

void create()
{
  set_name("讲经板", ({"board"}) );
  set("location", "/d/qujing/wuzhuang/jiangjing");
  set("board_id", "jiangjing_b");
  set("capacity", 100);
  set("long", "一块供五庄观弟子讲经论法的留言版。\n");
  setup();
  replace_program(BULLETIN_BOARD);
}

