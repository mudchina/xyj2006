// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dongwai.c

inherit ROOM;

void create ()
{
  set ("short", "金塔");
  set ("long", @LONG

山崖边有一座宝塔，金顶放光，彩气腾腾。青青香草秀，艳艳野
花开。远观如三岛天堂，近看似蓬莱仙境，果真是绝好去处。塔
前有一白玉石板(shi ban)。

LONG);

  set("exits", ([
        "northwest"      : __DIR__"songlin",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  set("item_desc",([
      "shi ban" : "\n碗子山波月洞\n\n"
     ]));

  setup();
}

void init ()
{
  add_action("do_break","break");
}

int do_break (string arg)
{
  object me = this_player();

  if (arg != "shi ban")
    return 0;

  message_vision ("$N大喝一声，使尽周身神力撞向白玉石板！\n\n",me);
  if (me->query("force")<300 ||
      me->query("mana")<300)
  {
    me->unconcious();
    me->set("force",0);
    me->set("mana",0);
  }
  else
  {
    me->add("force",-300);
    me->add("mana",-300);
    message_vision ("刹那间天崩地裂，金塔突然消失得无影无踪！\n",me);
    this_object()->recreate();
    message_vision ("\n但见：\n",me);
    message_vision (this_object()->query("long"),me);
    remove_call_out ("precreate");
    call_out ("precreate",10,this_object());
  }
  return 1;
}

void precreate (object me)
{
  tell_room (me,"轰隆一声巨响，一切都还原了！\n\n");
  me->create();
}

void recreate ()
{
  set ("short", "波月洞外");
  set ("long", @LONG

石涯高万丈，山大接青宵。根连地厚，峰插天高。两边杂树数千
棵，前后藤缠百余里。崖壁处有一大洞穴，阴气缭绕，石牙交错，
险象万生。

LONG);

  set("exits", ([
        // "northwest"  : __DIR__"songlin",
        "southeast"  : __DIR__"dong",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

