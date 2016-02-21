
inherit BULLETIN_BOARD;
void create()
{
set_name("昆仑山玉壁", ({ "board" }) );
set("location", "/d/kunlun/gate");
  set("board_id", "yubi_b");
  set("long",     "这是一块明亮如镜的石壁。\n" );
  setup();
  set("capacity", 100);
  replace_program(BULLETIN_BOARD);
}

