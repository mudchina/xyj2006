// mon@xyj 10/10/98

inherit ROOM;

void dest();

void create()
{
  set ("short", "舍利塔");
  set ("long", @LONG

峰岩重叠，涧壑湾环。虎狼成阵走，麂鹿作群行。千尺大蟒，万丈
长蛇。大蟒喷愁雾，长蛇吐怪风。道旁荆棘浅漫，岭上松楠秀丽。
薜萝满目，芳草连天。

山路边一座古塔，里面供奉着前辈高僧的舍利。后人也不断把寻到
的舍利子虔诚地埋在塔下(bury)。

LONG);

  set("exits", ([
	  "westdown":"/d/qujing/baoxiang/yelu"+
	  (random(7)+1),
	  ]));

  setup();
}

void init ()
{
    object me=this_player();

    if(me->query_temp("startroom")) {
	me->set("startroom",me->query_temp("startroom"));
    } else {
	me->delete("startroom"); // use default start room.
    }
    me->save();
    call_out("dest",2);
    add_action("do_bury","bury");
}

void go_back(object dest, object me)
{
    object env;
    if(!me) return;
    if(present("sheli zi",me)) return;

    env=environment(me);
    if(!env || env!=this_object()) return;
    message_vision("平地一阵清风，将$N轻轻卷了起来，带走了。\n",me);
    me->move(dest,1);
    message_vision("风尽处，$N走了出来。\n",me);
    return;
}
    
int do_bury(string arg)
{
    object me=this_player();
    object dest=me->query_temp("old_place");
    int i;
    object obj;

    if(dest)
	call_out("go_back",2,dest,me);

    if(!arg) return notify_fail("你要埋什么？\n");
    if(!obj=present(arg,me))
	return notify_fail("你身上没有这样东西。\n");
    if(obj->query("id")!="sheli zi")
	return notify_fail("这样东西不能埋在这里。\n");
    i=obj->query_amount();
    message_vision("$N恭恭敬敬地在塔下挖了个坑，将"+
	    chinese_number(i)+obj->query("base_unit")+
	    obj->query("name")+"放进去，又小心翼翼地培上土。\n",me);
    me->add("potential",4*i);
    tell_object(me,"善哉！善哉！你的潜能增加了"
	    +chinese_number(4*i)+"点！\n");
    destruct(obj);
    log_file("shelizi",ctime(time())+" "+me->query("id")+
	    " got "+4*i+" pot\n");
    return 1;
}

void dest()
{
    object* child=children(__DIR__"small_cave");
    int i=sizeof(child),j;
    object *obj;
    
    while(i--) 
	if(clonep(child[i])) {
	    obj=all_inventory(child[i]);
	    j=sizeof(obj);
	    while(j--) {
		if(userp(obj[j])) {
		    tell_object(obj[j],
			    "你只觉得天地仿佛都塌陷下来，你被猛地甩了出去．．．\n");
		    obj[j]->move(this_object(),1);
		    message_vision("$N一个跟头从杂草中飞了过来，满脸的迷茫。\n",
			    obj[j]);
		} 
	    }
	    destruct(child[i]);
	}
}

