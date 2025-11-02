# 빠른 시작 가이드

## Gazebo World 실행하기

### 🎯 올바른 문법

```bash
make px4_sitl gazebo-classic_모델명__world명
```

**중요**: 언더스코어 **2개** (`__`) 사용!

---

## 📦 빠른 명령어

### Warehouse (창고) - 추천! 🏆
```bash
cd ~/source4/drone_simulator/PX4-Autopilot
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
```
또는
```bash
cd ~/source4/drone_simulator/chapter3
./run_depth_warehouse.sh
```

### Empty (빈 환경)
```bash
make px4_sitl gazebo-classic_iris_depth_camera
```

### Baylands (야외)
```bash
make px4_sitl gazebo-classic_iris_depth_camera__baylands
```

### Yosemite (산악)
```bash
make px4_sitl gazebo-classic_iris_depth_camera__yosemite
```

---

## 🚁 전체 워크플로우

### Terminal 1: Gazebo Simulation
```bash
cd ~/source4/drone_simulator/PX4-Autopilot
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
```

### Terminal 2: Micro XRCE-DDS Agent
```bash
cd ~/source4/drone_simulator
./run_agent.sh udp4 -p 8888
```

### Terminal 3: Depth Camera Viewer
```bash
cd ~/source4/drone_simulator/chapter3
source /opt/ros/galactic/setup.bash
source ~/ros2_ws/install/setup.bash
python3 depth_camera_viewer.py
```

### Terminal 4: RViz2
```bash
source /opt/ros/galactic/setup.bash
ros2 run rviz2 rviz2
```

---

## ⚠️ 문제 해결

### Gazebo 창이 안 뜰 때
```bash
# 1. 모든 프로세스 종료
killall -9 px4 gzserver gzclient make

# 2. 잠금 파일 삭제
rm -rf /tmp/.gazebo*

# 3. 다시 실행
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
```

### "gzserver not ready yet" 메시지
- **정상입니다!** 10-30초 기다리세요
- Warning 메시지들도 무시해도 됩니다

### world: none으로 나올 때
- ❌ 잘못된 방법: `PX4_SITL_WORLD=warehouse make ...`
- ✅ 올바른 방법: `make px4_sitl gazebo-classic_iris_depth_camera__warehouse`

---

## 📋 사용 가능한 World 목록

| World 이름 | 용도 | 명령어 |
|-----------|------|--------|
| **warehouse** | SLAM, 실내 내비게이션 | `__warehouse` |
| empty | 기본 테스트 | (기본값) |
| baylands | 야외 비행 | `__baylands` |
| ksql_airport | 공항 환경 | `__ksql_airport` |
| mcmillan_airfield | 비행장 | `__mcmillan_airfield` |
| sonoma_raceway | 경주로 | `__sonoma_raceway` |
| yosemite | 산악 지형 | `__yosemite` |
| windy | 바람 시뮬레이션 | `__windy` |
| safe_landing | 착륙 테스트 | `__safe_landing` |

---

## 🎓 다음 단계

1. ✅ Warehouse 환경 실행
2. ✅ Depth camera 데이터 확인
3. ✅ RViz2로 시각화
4. 🚀 SLAM 알고리즘 통합 (Chapter 4)
5. 🚀 Obstacle avoidance 구현
