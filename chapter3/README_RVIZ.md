# RViz2로 Depth Camera 시각화하기

## 문제점
Gazebo의 depth camera는 BEST_EFFORT QoS를 사용하지만, RViz2는 기본적으로 RELIABLE QoS를 사용합니다. 이로 인해 직접 연결이 불가능합니다.

## 해결 방법
`depth_camera_viewer.py` 노드가 QoS 변환을 수행합니다:
- Gazebo 토픽을 BEST_EFFORT로 구독
- RELIABLE QoS로 재발행하여 RViz와 호환

## 실행 순서

### Terminal 1: PX4 Simulation with Depth Camera
```bash
cd ~/PX4-Autopilot
make px4_sitl gazebo-classic_iris_depth_camera
```

### Terminal 2: Micro XRCE-DDS Agent
```bash
cd ~/drone_simulator
./run_agent.sh udp4 -p 8888
```

### Terminal 3: Depth Camera Viewer (QoS Converter)
```bash
cd ~/drone_simulator/chapter3
source /opt/ros/humble/setup.bash
source ~/drone_simulator/ros2_ws/install/setup.bash
python3 depth_camera_viewer.py
```

### Terminal 4: RViz2
```bash
source /opt/ros/humble/setup.bash
ros2 run rviz2 rviz2
```

## RViz2 설정 방법

### 1. Fixed Frame 설정
- 왼쪽 패널에서 `Fixed Frame`을 `base_link` 또는 `map`으로 설정

### 2. Depth Image 추가
1. 왼쪽 하단 `Add` 버튼 클릭
2. `By topic` 탭 선택
3. `/camera/depth/image_raw/reliable` → `Image` 선택
4. `OK` 클릭

### 3. RGB Image 추가
1. `Add` 버튼 클릭
2. `/camera/image_raw/reliable` → `Image` 선택
3. `OK` 클릭

### 4. Point Cloud 추가 (3D 시각화)
1. `Add` 버튼 클릭
2. `By topic` 탭에서 `/camera/points/reliable` → `PointCloud2` 선택
3. `OK` 클릭
4. PointCloud2 디스플레이 설정:
   - `Style`: Points 또는 Flat Squares
   - `Size (Pixels)`: 3-5
   - `Color Transformer`: RGB8 또는 AxisColor

### 5. TF (Transform) 추가
1. `Add` 버튼 클릭
2. `By display type` 탭 선택
3. `TF` 선택
4. `OK` 클릭

## 사용 가능한 토픽

### Gazebo 원본 토픽 (BEST_EFFORT QoS)
- `/camera/depth/image_raw` - Raw depth 이미지
- `/camera/image_raw` - RGB 이미지
- `/camera/points` - 3D 포인트 클라우드
- `/camera/depth/camera_info` - 카메라 파라미터

### RViz 호환 토픽 (RELIABLE QoS)
- `/camera/depth/image_raw/reliable` - Depth 이미지 (RViz용)
- `/camera/image_raw/reliable` - RGB 이미지 (RViz용)
- `/camera/points/reliable` - 포인트 클라우드 (RViz용)

## 토픽 확인

```bash
# 모든 카메라 토픽 확인
ros2 topic list | grep camera

# Depth 이미지 정보 확인
ros2 topic info /camera/depth/image_raw/reliable

# 실시간 데이터 확인
ros2 topic echo /camera/depth/image_raw/reliable --once
```

## 트러블슈팅

### 이미지가 보이지 않는 경우:
1. `depth_camera_viewer.py`가 실행 중인지 확인
2. 노드 로그에서 메시지 수신 확인: "Messages received - Depth: XX, RGB: XX"
3. RViz에서 올바른 토픽 선택 확인 (`/reliable` 접미사 있는 토픽)

### Point Cloud가 보이지 않는 경우:
1. Fixed Frame이 올바르게 설정되었는지 확인
2. PointCloud2 display의 `Status`를 확인 (에러 메시지 확인)
3. TF가 올바르게 설정되었는지 확인

### QoS 호환성 경고가 나오는 경우:
- 원본 Gazebo 토픽 대신 `/reliable` 접미사가 붙은 토픽 사용
- `depth_camera_viewer.py` 노드가 실행 중인지 확인

## 센서 사양

- **해상도**: 848 x 480 pixels
- **거리 범위**: 0.2m ~ 65m
- **업데이트 속도**: ~10 Hz
- **모델**: Intel RealSense D455 시뮬레이션
- **FOV**: ~86° (1.5 radians)

## 데이터 활용

### Python에서 Depth 이미지 사용
```python
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

class DepthProcessor(Node):
    def __init__(self):
        super().__init__('depth_processor')
        
        qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        self.subscription = self.create_subscription(
            Image,
            '/camera/depth/image_raw',
            self.depth_callback,
            qos
        )
    
    def depth_callback(self, msg):
        # msg.data contains depth values
        # Process depth image here
        pass
```

## 다음 단계

이제 depth camera 데이터를 시각화할 수 있으므로:
1. SLAM 알고리즘 통합 (Chapter 4)
2. Obstacle avoidance 구현
3. 3D mapping 생성
