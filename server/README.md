# Robotrack's SmartHome Server

## Preparation

1. Install **PyEnv**
2. Download **Python 3.9.0**

   ```shell
   pyenv install 3.9.0
   ``` 

3. There is a `.python-version` file already in server root which tells **PyEnv** to use this specific version. If it's done right, you'll see correct version of Python installed

   ```shell
   pyenv exec python --version
   ``` 
   ```
   Python 3.9.0
   ```
    
4. Open server root via terminal and create virtual environment

   ```shell
   pyenv exec python -m pip install virtualenv
   virtualenv venv
   ```

5. Activate virtual environment

   - Windows
 
     ```shell
     .\venv\Scripts\activate.bat
     ```

   - Linux

     ```shell
     source ./venv/bin/activate
     ```

6. Install requirements

   - Windows
 
     ```shell
     pip install -r .\app\requirements.txt 
     ```

   - Linux

     ```shell
     pip install -r ./app/requirements.txt
     ```
