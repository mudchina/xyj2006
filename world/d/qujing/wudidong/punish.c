// Room: /d/qujing/wudidong/punish
inherit ROOM;

void create ()
{
  set ("short", "黑暗中");
  set ("long", @LONG

这里是一片黑暗，伸手不见五指。四处死沉沉地毫无声息，越发显得
阴森恐怖。突然间一阵冷风吹来，带来一股扑鼻的霉气。渐渐的，你
感到呼吸困难起来，看来这里并不透风。
LONG);
  setup();
}
void init()
{
    object me=this_player();

    if(me->query("startroom")!="/d/qujing/wudidong/punish")
	me->set("startroom_old", me->query("startroom"));
    me->set("startroom", "/d/qujing/wudidong/punish");
    add_action("do_search", "search");
    add_action("do_search", "jiancha");
    add_action("do_dig", "dig");
    add_action("do_dig", "wa");
}
int do_search(string arg)
{
    object me=this_player();
    if (arg) return notify_fail("这里没有 "+arg+"。\n");
    if (me->query("kee")*100/me->query("max_kee")< 30
     || me->query("sen")*100/me->query("max_sen")< 30)
        return notify_fail("都快累死了，还是老老实实地坐着吧！\n");
    me->start_busy(random(40-me->query_kar()));
    tell_object(me, "你左右看了看，戳了几下，发觉东边的尘土有些松动。\n");
    me->set_temp("mark/wudidong_know_about_punishroom", 1);
    return 1;
}
int do_dig(string arg)
{
    object me=this_player();

//    if (me->query_skill("tianmo", 1)<30)
//        return notify_fail("你还没学会无底洞的看家本领！\n");
    if (!me->query_temp("mark/wudidong_know_about_punishroom"))
        return notify_fail("挖什么？\n");
    tell_object(me, "你伸出双手，吹一口气，道：变！只见双手变成一对铁爪！\n");
    tell_object(me, "你舞动铁爪，瞬时间将松动的尘土挖开了！\n");
    tell_object(me, "你伸出铁爪一抖，变回了双手，从容不迫地从洞口爬了出去。\n");
    message_vision("只听一阵唏嗦声过后，$N不见了！\n", me);
    me->move(__DIR__"gongshi");
    me->set("startroom", me->query("startroom_old"));
    me->delete_temp("mark/wudidong_know_about_punishroom");
    message("vision", "西边石壁突然露出个大洞，"+me->name()+"从里面钻了出来。\n", me);
    return 1;
}
