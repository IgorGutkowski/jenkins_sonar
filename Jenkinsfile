pipeline {
    agent any

    tools {
        maven 'Maven 3.6.3'
    }

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Build') {
            steps {
                sh '''
                mkdir -p build && cd build
                cmake ..
                make
                '''
            }
        }
        
        stage('Test') {
            steps {
                sh '''
                cd build
                make test
                '''
            }
        }

        stage('Coverage') {
            steps {
                sh '''
                cd build
                gcov main.cpp
                gcovr -r . --xml -o coverage.xml
                '''
            }
            post {
                always {
                    cobertura coberturaReportFile: '**/coverage.xml'
                }
            }
        }

        stage('Static Analysis') {
            steps {
                sh '''
                cppcheck --enable=all --xml-version=2 src/*.cpp 2> cppcheck-report.xml
                '''
            }
        }

        stage('SonarQube Analysis') {
            steps {
                withSonarQubeEnv('SonarQube') {
                    sh 'sonar-scanner'
                }
            }
        }
    }

    post {
        always {
            echo 'Cleaning up'
            deleteDir() 
        }
        success {
            echo 'Pipeline succeeded!'
        }
        failure {
            echo 'Pipeline failed!'
        }
    }
}
