import cv2
import numpy as np

# 画像を読み込む
image = cv2.imread('your_image_with_boxes.jpg')
# オリジナルの画像を残しておく
original = image.copy()

# 1. 前処理
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(gray, (5, 5), 0)
# 二値化（閾値は画像の特性に合わせて調整が必要）
_, thresh = cv2.threshold(blurred, 127, 255, cv2.THRESH_BINARY)

# 2. 輪郭の検出
# cv2.RETR_EXTERNALは外側の輪郭のみを検出するモード
contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# 3. 輪郭の絞り込みと描画
for contour in contours:
    # 輪郭を多角形で近似する
    epsilon = 0.02 * cv2.arcLength(contour, True)
    approx = cv2.approxPolyDP(contour, epsilon, True)

    # 頂点が4つで、かつ一定以上の面積を持つものを「四角形」と判断
    if len(approx) == 4 and cv2.contourArea(contour) > 1000:
        # 輪郭を描画する
        cv2.drawContours(original, [approx], 0, (0, 255, 0), 3)

# 結果を表示
cv2.imshow('Detected Boxes', original)
cv2.waitKey(0)
cv2.destroyAllWindows()