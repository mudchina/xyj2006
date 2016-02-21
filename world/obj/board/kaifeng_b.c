inherit BULLETIN_BOARD;

void create()
{
  set_name("ÌúËşÁôÑÔ±Ú", ({"board"}) );
  set("location", "/d/kaifeng/tieta");
  set("board_id", "kaifeng_b");
  set("capacity", 100);
  set("long", "ÌúËşÏÂÒ»¿éÁôÑÔ±Ú£¬ÉÏÃæĞ´ÂúÁËÁôÑÔ¡£\n");
  setup();
  replace_program(BULLETIN_BOARD);
}

