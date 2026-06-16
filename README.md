# SpartHW3

## 3종류 장애물 구성 

- MovingFloor: 좌우로 이동하며 밟을 수 있는 발판
- RollingTrap: T자형으로 만들어져 중심축을 기발으로 회전 (Yaw)하는 장애물
- FallingBall: 위에서 떨어지는 장애물
	* FallingBall 자체는 StaticMesh와 RootScene만을 포함
	* Spawn을 위하여 FallingBallSpawnManager를 이용

## FallingBallSpawnManager

- FallingBall 스폰을 위한 액터 클래스 
- 최소 최대의 X,Y를 각각 지정하여 랜덤한 좌표로 스폰
- 최적화를 위하여 스폰 이후 10초 뒤 소멸

## 기타

원래 Tick 이용한 함수에서 Timer를 이동하도록 수정하였습니다.
