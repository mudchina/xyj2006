// where.c
// 06-14-95

inherit F_CLEAN_UP;
int where_all();

int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;

	if (!str)
		return where_all();
        notify_fail("指令格式：where <人物或档名>\n"); 
	ob = find_player(str);
	if( !ob ) ob = find_living(str);

	if( !ob ) ob = LOGIN_D->find_body(str);
	/*  added by mon. 2/23/97 */

//	if( !ob || !me->visible(ob)) {
	if( !ob ) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		
		if(sizeof(ob_list)<1)
		    return notify_fail("Can't find such player or file.\n");

		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}

//	if (!ob) return notify_fail("现在没这个人。\n");

	where = environment(ob);
	if (!where) return notify_fail("这个人("+file_name(ob)+
	   ")不知道在那里耶。。。\n");
	printf("%s(%s)现在在%s(%s).\n",
		(string)ob->name(),
		(string)ob->query("id"),
		undefinedp(where->query("short"))?
                  where->short():
                  where->query("short"),
		(string)file_name(where));
	return 1;
}

int where_all()
{
    string str;
    object *list;
    int i, j, ppl_cnt;
    object me, where;
        me = this_player();
        str = "■ " + MUD_NAME + "\n";
        str += "—————————————————————————————————————\n";
        str += "使用代号      中文姓名          目前位置      \n";
        str += "—————————————————————————————————————\n";
        list = users();
    j = sizeof(list);
    while( j-- ) {
        where=environment(list[j]);
        // Skip those users in login limbo.
        if( !where ) continue;
        str = sprintf("%s%-14s%-18s%-s(%s)\n",
                                str,
                                list[j]->query("id"),
                                list[j]->query("name"),
            where->query("short"),
            file_name(where)
                        );
                }
        str += "—————————————————————————————————————\n";
    me->start_more(str);
    return 1;
}


int help(object me)
{
	write(@HELP
指令格式: where <玩家的 ID>

这个指令是用来得知玩家目前所在的位置.

HELP
	);
	return 1;
}

