
mapping *sort_team (mapping *team)
{
  int i, j, size = sizeof(team)-1;

  for (i=size-2; i>=0; i--)
  {
    reset_eval_cost();
    for (j=0; j<=i; j++)
    {
      mapping member1 = team[j+1];
      mapping member2 = team[j+2];

      if (member1["combat_exp"] > member2["combat_exp"])
      {
        team[j+1] = member2;
        team[j+2] = member1;
      }
    }
  }
}

