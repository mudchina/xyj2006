// mon 9/25/97

int valid_move(object me)
{
        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");

        if( me->query_temp("no_move") )
//              return notify_fail("你被定住了，哪里动得了！\n");
// mon 8/11/97. change the fail message since not only dingshen
// can lead to no_move.
                return notify_fail("你现在不能移动！\n");
        return 1;
}
