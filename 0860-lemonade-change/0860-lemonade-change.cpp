class Solution {
public:

	bool IsCanChange(map<int,int,std::greater<int>>& map, int target)
	{
		// target 15
		
		for(auto& value : map)
		{
			if(target < value.first)
			{
				continue;
			}
			int result = 0;
			int loop = value.second;

			for(int i=0; i<loop; ++i)
			{
				if(target - value.first <0)
				{
					break;
				}
				target -= value.first;

				map[value.first]--;
			}
		}

		if(target == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool lemonadeChange(vector<int>& bills)
	{
		map<int,int,std::greater<int>> map = {{5,0},{10,0},{20,0} };

		for (int i = 0; i < bills.size(); ++i)
		{
			int toApplyMoney = bills[i] - 5;

			if (0 == toApplyMoney)
			{
				map[5]++;
			}
			else
			{
				if (map[toApplyMoney] == 0)
				{
					if(IsCanChange(map, toApplyMoney))
					{
						map[bills[i]]++;
					}
					else
					{
						return false;
					}
				}
				else
				{
					map[toApplyMoney]--;
					map[bills[i]]++;

				}
			}
		}

		return true;
	}
};