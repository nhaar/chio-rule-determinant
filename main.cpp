#include <vector>
#include <tuple>
#include <iostream>

class 正方行列 {
private:
  std::vector<std::vector<double>> ベクター;

public:
  正方行列(std::vector<std::vector<double>> ベクター) : ベクター{ベクター} {
    int じげん = ベクター.size();
    for (int i = 0; i < じげん; i++) {
      if (ベクター.at(i).size() != じげん) {
        throw "行列は正方行列ではない。";
      }
    }
  }

  int 次元() {
    return ベクター.size();
  }

  void 示す() {
    for (int i = 0; i < 次元(); i++) {
      for (int j = 0; j < 次元(); j++) {
        std::cout << ベクター.at(i).at(j) << " ";
      }
      std::cout << std::endl;
    }
  }

  std::tuple<int, int> 一を見つける() {
    for (int i = 0; i < 次元(); i++) {
      for (int j = 0; j < 次元(); j++) {
        if (ベクター.at(i).at(j) == 1) {
          return { i, j };
        }
      }
    }

    return {-1, -1};
  }

  正方行列 削減() {
    std::vector<std::vector<double>> べくたー;

    std::tuple<int, int> いち = 一を見つける();

    int いちi = std::get<0>(いち);
    int いちj = std::get<1>(いち);

    if (いちi == -1) {
      throw "行列に１がないわけで削減できない";
    }

    for (int i = 0; i < 次元(); i++) {
      if (i != いちi) {
        std::vector<double> れつ;
        for (int j = 0; j < 次元(); j++) {
          if (j != いちj) {
            れつ.push_back(
              ベクター.at(i).at(j) - ベクター.at(i).at(いちj) * ベクター.at(いちi).at(j)
            );
          }
        }
        べくたー.push_back(れつ);
      }
    }

    return 正方行列(べくたー);
  }

  double ゲット(int i, int j) {
    return ベクター.at(i).at(j);
  }

  void 設定(int i, int j, double あたい) {
    ベクター.at(i).at(j) = あたい;
  }

  bool 一が含めている() {
    std::tuple<int, int> いち = 一を見つける();
    return std::get<0>(いち) != -1;
  }

  std::tuple<int, int> ゼロじゃない位置を見つける() {
    for (int i = 0; i < 次元(); i++) {
      for (int j = 0; j < 次元(); j++) {
        if (ゲット(i, j) != 0) {
          return { i, j };
        }
      }
    }

    return { -1, -1 };
  }
};

double 行列式を見つける(正方行列 ぎょうれつ) {
  if (ぎょうれつ.次元() == 1) {
    return ぎょうれつ.ゲット(0, 0);
  } else {
    if (ぎょうれつ.一が含めている()) {
      return 行列式を見つける(ぎょうれつ.削減());
    } else {
      std::tuple<int, int> ぜろじゃない = ぎょうれつ.ゼロじゃない位置を見つける();
      int i = std::get<0>(ぜろじゃない);
      int j = std::get<1>(ぜろじゃない);
      if (i == -1) {
        return 0;
      } else {
        double ようそ = ぎょうれつ.ゲット(i, j);
        double いんすう = 1 / ようそ;
        ぎょうれつ.設定(i, j, 1);
        for (int れつj = 0; れつj < ぎょうれつ.次元(); れつj++) {
          if (j != れつj) {
            ぎょうれつ.設定(i, れつj, いんすう * ぎょうれつ.ゲット(i, れつj));
          }
        }
        return 行列式を見つける(ぎょうれつ) * ようそ;
      }
    }
  }
}

int main() {
  int じげん;
  std::vector<std::vector<double>> べくたー;
  
  std::cout << "gyouretu no jigen wo nyuuryoku:" << std::endl;
  std::cin >> じげん;

  std::cout << "gyouretu no youso wo nyuuryoku (hidari kara, ue kara):" << std::endl;

  for (int i = 0; i < じげん; i++) {
    std::vector<double> れつ;
    for (int j = 0; j < じげん; j++) {
      double かず;
      std::cin >> かず;
      れつ.push_back(かず);
    }
    べくたー.push_back(れつ);
  }

  std::cout << "ika no gyouretu no gyouretusiki wo keisan simasu." << std::endl;
  正方行列 ぎょうれつ = 正方行列(べくたー);

  ぎょうれつ.示す();

  std::cout << "gyouretusiki: " <<  行列式を見つける(ぎょうれつ) << std::endl;
}

