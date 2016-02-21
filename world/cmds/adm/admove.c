// by Canoe
// 测试物品的给予时的消失情况
// 只能给到testone身上
// 2001.07.02
int main(object me, string arg)
{
object who,book;
if( !objectp(book = present(arg, me)) ) 
                        return notify_fail("你身上没有"+arg+"这样东西。\n");
if(!arg) return notify_fail("你要给testone什么东西？\n");
if(!who=find_player("testone"))
                return notify_fail("testone不在mud里。\n");
if(!book->move(who))
                return notify_fail("移动失败。\n");
write(arg+"成功移动到testone身上。\n");
return 1;
} 
 
