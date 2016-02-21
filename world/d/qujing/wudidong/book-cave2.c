// Room: /d/qujing/wudidong/book_cave1
// created 9-14-97 pickle
/************************************************************/

inherit ROOM;
#include <ansi.h>

// some global variables.
#include <ansi.h>

string book="/d/obj/book/kugu-";

/************************************************************/

void create ()
{
  object dao, shu;

  set ("short", "洞穴");
  set ("long", @LONG

这里的洞穴突然大了许多。四壁插着几支牛油蜡烛，发出点若明若暗
的光。洞穴里空阔的很，除了北边靠墙处一张巨大的石桌外，什么都
没有。迎面墙上似乎刻着一排字(zi)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southup" : __DIR__"book-cave1",
]));
  set("item_desc", ([
	"字": RED"汝既至此，乃是与吾有缘。既入吾门，则千刀万剐，在所不辞！"NOR"\n下面似乎有一排小字。(warning)\n",
	"zi": RED"汝既至此，乃是与吾有缘。既入吾门，则千刀万剐，在所不辞！"NOR"\n下面似乎有一排小字。(warning)\n",
	"warning": RED"吾门门规不多，仅忌贪。望汝好自为之。\n"NOR,
	]) );
  setup();
  if( "/d/obj/weapon/blade/kugudao"->in_mud() == 0 )   {
	 dao= new("/d/obj/weapon/blade/kugudao");
	 dao->move(this_object());
  }
  if((book+"1")->in_mud() == 0)
  {
	shu=new(book+"1");
	shu->move(this_object());
  }
  if((book+"2")->in_mud() == 0)
  {
	shu=new(book+"2");
	shu->move(this_object());
  }
  if((book+"3")->in_mud() == 0)
  {
	shu=new(book+"3");
	shu->move(this_object());
  }
}

/************************************************************/
int valid_leave(object me, string dir)
{
    object *inv;
    int i, treasure_count;

    inv=all_inventory(me);
    i=sizeof(inv);
    while (i--)
    {
	if (inv[i]->query("name_recognized") == "枯骨刀秘笈")
	    treasure_count+=1;
        if (inv[i]->query("name_recognized") == "枯骨刀")
	    treasure_count+=1;
	continue;
    }
    if (treasure_count > 1)
	return notify_fail("别太贪心了！\n");
    return ::valid_leave(me, dir);
}
