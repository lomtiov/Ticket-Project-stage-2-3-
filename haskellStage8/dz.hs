-- Бесконечный список частичных сумм гармонического ряда
harmonicSeries :: [Double]
harmonicSeries = scanl1 (+) (map (\i -> 1 / fromIntegral i) [1..])

-- Функция main для запуска программы
main :: IO ()
main = do
    print $ take 10 harmonicSeries

