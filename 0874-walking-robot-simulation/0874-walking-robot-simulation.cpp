// Point 클래스 정의
struct Point {
	int x, y;

	// 두 Point 객체의 동등성 비교를 위한 operator== 정의
	bool operator==(const Point& other) const {
		return x == other.x && y == other.y;
	}
};

// 사용자 정의 해시 함수
struct PointHash {
	std::size_t operator()(const Point& p) const {
		// 해시값을 계산하는 방법 (x와 y를 조합)
		return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
	}
};



class Solution {
public:
	int x = 0;
	int y = 0;
	int maxValue {0};
	int arr[4][2] = { {0,1} ,{1,0},{0,-1},{-1,0} };
	std::unordered_set<Point, PointHash> gSet;


	void Go(int direction, int n, vector<vector<int>>& obstacles, int& x, int& y)
	{
		for (int i = 0; i < n; ++i)
		{
			if(x + arr[direction][0] <-30000 || y + arr[direction][1] <-30000 || x + arr[direction][0] > 30000 || y + arr[direction][0] > 30000)
			{
				break;
			}

			if(gSet.contains({ x + arr[direction][0] , y + arr[direction][1] }) == true)
			{
				break;
			}

			x = x + arr[direction][0];
			y = y + arr[direction][1];
		}

		maxValue = std::max(maxValue, (x * x) + (y * y));
	}

	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
	{
		int x = 0;
		int y = 0;
		int direction = 0;

		for(int i=0; i<obstacles.size();++i)
		{
			gSet.insert({ obstacles[i][0] ,obstacles[i][1] });
		}

		for (int i = 0; i < commands.size(); ++i)
		{
			if (commands[i] < 0)
			{
				if (commands[i] == -1) // turn right
				{
					direction = std::abs((direction + 1) % 4);
				}
				else if (commands[i] == -2) // turn left
				{
					if(direction -1 <0)
					{
						direction =4 + (direction - 1);
					}
					else
					{
						direction = std::abs((direction - 1) % 4);
					}
				}
			}
			else
			{
				Go(direction, commands[i], obstacles, x, y);
			}
		}
		return maxValue;
	}
};
