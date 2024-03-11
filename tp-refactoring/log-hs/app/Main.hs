import System.IO


add3 :: Int -> Int 
add3 = (+3)

mul2 :: Int -> Int
mul2 = (*2)

mycompute :: Int -> IO Int
mycompute v0 = do
    putStrLn ("add3 " ++ show v0)
    let v1 = add3 v0
    putStrLn ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2

myComputeFile::Int -> IO Int
myComputeFile v0 = do
    handle <- openFile "log.txt" WriteMode
    hPutStrLn handle ("add3 " ++ show v0)

    let v1 = add3 v0
    hPutStrLn handle ("mul2 " ++ show v1)
    let v2 = mul2 v1

    hClose handle
    return v2

logFile::String -> IO()
logFile txt = do
    handle <- openFile "log.txt" AppendMode
    hPutStrLn handle txt
    hClose handle

myComputeF :: (String -> IO()) -> Int -> IO Int
myComputeF logF v0 = do
    logF ("add3 " ++ show v0)
    let v1 = add3 v0
    logF ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2
 

main :: IO ()
main = do
    putStrLn "this is log-hs"
    
    res <- mycompute 18
    print res
    
    res2 <- myComputeFile 18
    print res2

    res3 <- myComputeF logFile 18
    print res3

    handle <- openFile "log.txt" WriteMode
    resFile <- myComputeF (hPutStrLn handle) 18
    hClose handle
    print resFile
    
